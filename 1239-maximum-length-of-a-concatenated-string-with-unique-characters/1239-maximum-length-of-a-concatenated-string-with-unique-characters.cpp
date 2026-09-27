class Solution {
public:

    // Recursion

    bool NotDuplicates(string s1, string s2)
    {
        vector<int>temp(26,0);

        for(int i=0;i<s1.size();i++)
        {
            temp[s1[i]-'a']++;

            if(temp[s1[i]-'a'] > 1)  // to handle agr phli string me hi duplicates hue fir bhi toh concate krna possible nhi hona chahiye
              return 0;
        }

        for(int i=0;i<s2.size();i++)
        {
            if(temp[s2[i]-'a'])
              return 0;

            temp[s2[i]-'a']++; // iss se dusri string me age duplicate hue toh bhi ans posssible nhi hai kyuki jisko attach kr rhe hai tmep me usme bhi toh duplicate nhi hone chahiye toh usi ke liye ye kiya hai kyuki s2 me mera array se string aa rhi thi ans a1 me temp aa rhi thi   yaa aisa bhi kr skte hai find function me se hi s1 me array ki string bheje and s2 me temp bheje
        }
        return 1;
    }
    
    int find(int index, int n, vector<string>&arr,string temp)
    {
        if(index>=n)
        {
            int ans = temp.size();
            return ans;
        }    

        int take=0, notTake=0;
        
        if(NotDuplicates(temp,arr[index]))
        {
            string temp_new =  temp + arr[index]; 
            take = find(index+1, n, arr, temp_new);
        }

        notTake = find(index+1, n, arr, temp);

        return max(take, notTake);
    }

    int maxLength(vector<string>& arr) {

        int n = arr.size();
        string temp = "";

        return  find(0,n,arr,temp);

    }
};