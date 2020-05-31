class Solution(object):
      

    def kClosest(self, points, K):
        points.sort(key = lambda K: K[0]**2 + K[1]**2) 
        return points[:K] 
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        