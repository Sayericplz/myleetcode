public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = numbers.length;
        int index[] = new int[2];
        ArrayList<Node> nodes = new ArrayList<Node>();
        for(int i = 0;i < len;i++)
            nodes.add(new Node(i+1,numbers[i]));
        Collections.sort(nodes);
        int i = 0, j = len-1;
        while(true)
        {
            int sum = nodes.get(i).val + nodes.get(j).val;
            if(sum == target)
                break;
            if(sum < target)
                i++;
            else
                j--;
        }
        index[0] = nodes.get(i).index;
        index[1] = nodes.get(j).index;
        if(index[0] > index[1])
        {
            int tmp = index[0];
            index[0] = index[1];
            index[1] = tmp;
        }
        return index;
    }

    class Node implements Comparable
    {
        public int index;
        public int val;
        public Node(int index, int val)
        {
            this.index = index;
            this.val = val;
        }

        public int compareTo(Object o)
        {
            Node n = (Node)o;
            return this.val - n.val;
        }
    }
}