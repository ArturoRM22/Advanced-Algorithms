import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial import Voronoi, voronoi_plot_2d

# Coordenadas de los puntos
points = np.array([
    [200, 500],
    [300, 100],
    [450, 150],
    [520, 480]
])

# Generar el diagrama de Voronoi
vor = Voronoi(points)

# Graficar el diagrama de Voronoi
fig, ax = plt.subplots()
voronoi_plot_2d(vor, ax=ax, show_vertices=False, line_colors='orange', line_width=2, line_alpha=0.6, point_size=10)

# Graficar los puntos
ax.plot(points[:, 0], points[:, 1], 'o', color='red')

# Configurar límites del gráfico
ax.set_xlim(0, 600)
ax.set_ylim(0, 600)

# Título y ejes
ax.set_title("Diagrama de Voronoi")
ax.set_xlabel("Coordenada X")
ax.set_ylabel("Coordenada Y")

plt.show()

