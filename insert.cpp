 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool sortInv( const Interval &v1, const Interval &v2)
{  
    return v1.start < v2.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),sortInv);
        vector<Interval> res;
        vector<Interval>::iterator s,e;
        s = intervals.begin();
        while(s->end < newInterval.start)
        {
        	res.push_back(*s);
        	s++;
        }
        e = s;
        while(s->start <= newInterval.end && s != intervals.end())
        {
        	int maxend = s->end; 
        	while(maxend >= e->start && e != intervals.end())
        	{
        		if(e->end > maxend) maxend = e->end;
        		e++;
        	}
        	struct Interval i(s->start,maxend);
        	res.push_back(i);
        	s = e;
        }
        while(s != intervals.end())
        {
        	res.push_back(*s);
        	s++;
        }
        return res;
    }
};