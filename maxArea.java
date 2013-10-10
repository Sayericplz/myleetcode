public class Solution {
    public int maxArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int i = 0, j = height.length-1;
        int maxa = 0;
        while(i <= j)
        {
        	int h;
        	if(height[i] > height[j])
        		h = height[j--];
        	else
        		h = height[i++];
        	int area = h * (j-i+1);
        	if(area > maxa) maxa = area;
        }
        return maxa;
    }
}