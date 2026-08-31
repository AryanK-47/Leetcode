class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays( nums2, nums1);
        }
        int n=nums1.size();
        int m=nums2.size();

        int low=0;
        int high=n;

        while(low<=high){
            int mid=(low+high)/2;
            int left=(n+m+1)/2-mid;

            int x1=(mid==0)?INT_MIN:nums1[mid-1];
            int x2=(left==0)?INT_MIN:nums2[left-1];

            int x3=(mid==n)?INT_MAX:nums1[mid];
            int x4=(left==m)?INT_MAX:nums2[left];

            if(x1<=x4 && x2<=x3){
                if((m+n)%2==1){
                    return max(x1,x2);
                }
                return (max(x1,x2)+min(x3,x4))/2.0;
            }
            if(x1>x4){
                high=mid-1;
            }
            else low=mid+1;
        }
        return -1;
    }

};