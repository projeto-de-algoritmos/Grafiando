import networkx as nx
import matplotlib.pyplot as plt

G = open("entradas.txt", 'r')
G = nx.read_edgelist("entradas.txt", delimiter=" ")

# plot do grafo
nx.draw(G, with_labels=True, node_size= 500)
plt.show()