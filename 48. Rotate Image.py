def get_points(matrix_size, x, y):
    return [(y, matrix_size-x),(matrix_size-x, matrix_size-y), (matrix_size-y,x)]

class Solution:
    def rotate(self, matrix: 'List[List[int]]') -> 'None':
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        matrix_edge_size=len(matrix)
        
        for x in range(0, matrix_edge_size//2):
            for y in range(x, matrix_edge_size-1-x):
                for (x1, y1) in get_points(matrix_edge_size-1, x, y):
                    (matrix[x][y],matrix[x1][y1])=(matrix[x1][y1],matrix[x][y])