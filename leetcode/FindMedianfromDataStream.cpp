class MedianFinder {
public:
    vector<int> number;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(number.empty()) {
            number.push_back(num);
            return;
        }
        int insert_idx = my_lower_bound(num);
        number.insert(number.begin() + insert_idx, num);
    }

    int my_lower_bound(int num) {
        int s = 0;
        int e = number.size();
        int mid;

        while (e > s) {
            mid = (e + s) / 2;
            if(number[mid] >= num){
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return e;
    }
    
    double findMedian() {
        int n = number.size();
        return n & 1 ? number[n / 2] : ((double) number[n / 2 - 1] + number[n / 2]) * 0.5;
    }
};