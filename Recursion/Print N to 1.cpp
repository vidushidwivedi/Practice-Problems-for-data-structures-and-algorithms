 vector<int> ans;

void print(int i,int n){

    if(i>n) return;

    print(i+1,n);

    ans.push_back(i);

}

vector<int> printNos(int x) {

   print(1,x);

   return ans;

}