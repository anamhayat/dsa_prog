# graph using dictionaries


''' pseudocode DFS
	init graph
	// stack is being used implicitly
	init visited
	DFS(s):
		s.append(visited)
		for w in neigbours(s):
			if w not in visited:
				DFS(w)
		return
'''
G = {"1": ["2", "3", "4"],
     "2": ["1", "3"],
     "3": ["1", "2", "4", "5"],
     "4": ["1", "3", "5"],
     "5": ["3", "4", "6", "7"],
     "6": ["5"],
     "7": ["5"]}
visited = []

def DFS(s):
    visited.append(s)
    print('F', end= ' ')
    for w in G[s]:
        if w not in visited:
            DFS(w)
    print('B', end= ' ')
    return




# driver
start = input("Enter starting node: ")
DFS(start)
print("\n",visited)
