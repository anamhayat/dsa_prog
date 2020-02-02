''' pseudocode for BFS
	init graph G
    init queue q
	init mark_list, named visted
	BFS(s):
        visited.append(s)
		q.enqueue(s)
        while(visted.size < |V|)):
            q.dequeue()
            for w in neighbours(s):
                if w not in visited:
                    visited.append(w)
                    q.enqueue(w)
            s = q.dequeue() // set the next point of exploration
    return
'''
# when all children have come, no need for a parent, ever. dequeue it.
G = {'1': [ '2','3', '4'],
     '2': ['1', '3'],
     '3': ['1', '2', '4', '5'],
     '4': ['1', '3', '5'],
     '5': ['3', '4', '6', '7'],
     '6': ['5'],
     '7': ['5']}
G2 = {'1': ['2', '3', '4'],
      '2': ['1', '5', '6', '7'],
      '3': ['1','8'],
      '4': ['1'],
      '5': ['2'],
      '6': ['2'],
      '7': ['2'],
      '8': ['3','9'],
      '9': ['8']
      }

visited = []
q = []
def BFS(s):
    visited.append(s)
    q.append(s) # add start to queue
    # while len(visited) < len(G2):
    while len(visited)<len(G):
    	# visited.append()
    	
        s = q.pop(0)  # the parent whose children will be visited, the OPEN thing
        for w in G[s]:
            if w not in visited and not in q: # TC = O(V)
                visited.append(w)	# CLOSED thing
                print(w,end=' ')
                q.append(w)  # enqueue, i.e add from right
            
    return
# driver
start = input('Enter starting node: ')
BFS(start)
# print('\n', visited)
