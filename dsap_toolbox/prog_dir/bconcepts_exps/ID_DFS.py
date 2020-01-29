'''
DB_DFS(s):
    max_depth = 0
    while True: # we want to avoid the max_depth calculation
        max +=1
        DFS, with extra condition
'''

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
# init stack and visited
st = []  # s.append() for insert, s.pop() for removal
visited = []
def DB_DFS_iter(s):
    visited.append(s)
    depth = 0
    while len(visited) < len(G):
        depth += 1
        print('Depth:',depth)
        while len(visited)<len(G) and len(st)<=depth:
            flag = False
            for w in G[s]:
                if w not in visited:
                    flag = True
                    visited.append(w)
                    print(w)
                    st.append(s)
                    s = w
                    break
            if flag == True:
                continue
            if len(st)!=0:
                s = st.pop()# reaches here only if all neighbours are in visited array
# driver
s = input("Enter starting node: ")
DB_DFS_iter(s)
