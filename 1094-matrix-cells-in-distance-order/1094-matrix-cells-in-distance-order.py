from typing import List

class Solution:
    def allCellsDistOrder(self, rows: int, cols: int, rCenter: int, cCenter: int) -> List[List[int]]:
        all_cells = [[r, c] for r in range(rows) for c in range(cols)]
        
        all_cells.sort(key=lambda x: abs(x[0] - rCenter) + abs(x[1] - cCenter))
        
        return all_cells