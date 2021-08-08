import networkx as nx
import matplotlib.pyplot as plt

nomes = [(14, 15), (0,3), (2,3), (6,3), (8,3), (10, 9), (8,12), (14, 15), (14, 10), (6,5), (10,11),( 11, 7), (4,8), (0, 1), (1,2), (12, 13), (15, 3)]

G = nx.Graph()
G.add_edges_from(nomes)

val_map = {'A': 1.0,
           'D': 0.5,
           'H': 0.0}


pos = nx.spring_layout(G)

nx.draw(G, pos)
nx.draw_networkx_labels(G, pos)


plt.show()