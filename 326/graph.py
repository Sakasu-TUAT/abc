import networkx as nx
import matplotlib.pyplot as plt

# グラフの作成
G = nx.Graph()
G.add_edge('A', 'B', weight=4)
G.add_edge('A', 'C', weight=2)
G.add_edge('B', 'C', weight=5)
G.add_edge('B', 'D', weight=10)
G.add_edge('C', 'D', weight=3)
G.add_edge('D', 'E', weight=7)
G.add_edge('E', 'F', weight=1)

# Dijkstraアルゴリズムの実装
shortest_paths = nx.single_source_dijkstra(G, source='A')

for node, distance in shortest_paths[0].items():
    print(f"Shortest path from A to {node} is {distance}")

# グラフの可視化
pos = nx.spring_layout(G, seed=42)
labels = {node: f"{node}\n({shortest_paths[0][node]:.1f})" for node in G.nodes()}

plt.figure(figsize=(10, 6))
nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue', font_size=10, font_color='black')
nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): G[u][v]['weight'] for u, v in G.edges()}, label_pos=0.5)
nx.draw_networkx_labels(G, pos, labels, font_size=8, font_color='black')
plt.title("Dijkstra's Algorithm")
plt.axis('off')
plt.show()
