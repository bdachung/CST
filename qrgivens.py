import numpy as np

def givensrotation(a,b):
    #return (c,s)
    if(b==0):
        return (1,0)
    else:
        if np.abs(b) > np.abs(a):
            r = a / b
            s = 1 / np.sqrt(1 + r*r)
            c = s*r
            return (c,s)
        else:
            r = b / a
            c = 1 / np.sqrt(1 + r*r)
            s = c*r
            return (c,s)

def qrgiven(A):
    #return (Q,R)
    m, n = A.shape
    Q = np.identity(m)
    R = np.copy(A)
    for j in range(n):
        for i in range(m-1,j,-1):
            G = np.identity(m)
            c,s = givensrotation(R[i-1,j],R[i,j])
            G[i,i] = c
            G[i-1,i-1] = c
            G[i-1,i] = s
            G[i,i-1] = -s
            R = G @ R
            Q = Q @ np.transpose(G)
    return (Q,R)

A = np.array([[1,1,1], [1,2,1], [1,1,2], [2,3,4]])
Q,R = qrgiven(A)
print("Original matrix A:\n",A)
print("Q:\n",Q)
print("R:\n",R)
print("Q matmul R:\n",Q@R)

