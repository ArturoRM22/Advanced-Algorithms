#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <vector>

struct Point {
    double x, y;
    bool operator==(const Point& other) const {
        return abs(x - other.x) < 1e-9 && abs(y - other.y) < 1e-9;
    }
};

struct Line {
    double a, b, c; // ax + by = c
};

struct Region {
    Point site;
    std::vector<Point> vertices;
};

// Calculate perpendicular bisector line between two points
Line getBisector(const Point& p1, const Point& p2) {
    Line bisector;
    Point mid = {(p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0};
    
    // Get perpendicular vector
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    
    bisector.a = dx;
    bisector.b = dy;
    bisector.c = dx * mid.x + dy * mid.y;
    
    return bisector;
}

// Find intersection of two lines
Point getIntersection(const Line& l1, const Line& l2) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (abs(det) < 1e-9) {
        return {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()};
    }
    
    double x = (l2.b * l1.c - l1.b * l2.c) / det;
    double y = (l1.a * l2.c - l2.a * l1.c) / det;
    return {x, y};
}

// Check if a point is closer to site than to other points
bool isValidVertex(const Point& vertex, const Point& site, const std::vector<Point>& points) {
    if (!std::isfinite(vertex.x) || !std::isfinite(vertex.y)) {
        return false;
    }
    
    double siteDistance = hypot(vertex.x - site.x, vertex.y - site.y);
    for (const auto& point : points) {
        if (point == site) continue;
        double distance = hypot(vertex.x - point.x, vertex.y - point.y);
        if (distance < siteDistance - 1e-9) {
            return false;
        }
    }
    return true;
}

std::vector<Point> calculateVoronoiCell(const Point& site, const std::vector<Point>& points) {
    std::vector<Point> vertices;
    std::vector<Line> bisectors;
    
    // Generate all perpendicular bisectors
    for (const auto& other : points) {
        if (other == site) continue;
        bisectors.push_back(getBisector(site, other));
    }
    
    // Find all valid intersections
    for (size_t i = 0; i < bisectors.size(); ++i) {
        for (size_t j = i + 1; j < bisectors.size(); ++j) {
            Point intersection = getIntersection(bisectors[i], bisectors[j]);
            if (isValidVertex(intersection, site, points)) {
                vertices.push_back(intersection);
            }
        }
    }
    
    // Sort vertices counterclockwise around the site
    if (!vertices.empty()) {
        sort(vertices.begin(), vertices.end(), [&site](const Point& a, const Point& b) {
            double angleA = atan2(a.y - site.y, a.x - site.x);
            double angleB = atan2(b.y - site.y, b.x - site.x);
            return angleA < angleB;
        });
    }
    
    return vertices;
}

std::vector<Region> constructVoronoiDiagram(std::vector<Point>& points) {
    std::vector<Region> regions;
    for (const auto& site : points) {
        Region region;
        region.site = site;
        region.vertices = calculateVoronoiCell(site, points);
        regions.push_back(region);
    }
    return regions;
}
