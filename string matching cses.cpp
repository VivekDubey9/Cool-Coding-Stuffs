#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// Function to compute prefix hashes
vector<long long> get_hash(const string &s) {
    vector<long long> hsh(s.size() + 1, 0);
    for (int i = 0; i < (int)s.size(); i++) {
        hsh[i + 1] = (hsh[i] * 31 + (s[i] - 'a' + 1)) % mod;
    }
    return hsh;
}

int rabin_karp_algo(string s, string t) {
    vector<long long> hsh_s = get_hash(s);
    vector<long long> hsh_tgt = get_hash(t);

    int k = (int)t.size();
    int cnt = 0;
    long long target_hash = hsh_tgt[k];

    // Precompute powers of 9973
    vector<long long> p_pow(s.size() + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= (int)s.size(); i++)
        p_pow[i] = (p_pow[i - 1] * 9973) % mod;

    // Rolling hash substring comparison
    for (int i = k; i <= (int)s.size(); i++) {
        long long curr_hsh = (hsh_s[i]+mod - ((hsh_s[i - k] * p_pow[k]) % mod)) % mod;

        if (curr_hsh == target_hash) {
           cnt++;
        }
    }

    return cnt;
}





//abcababcab
//[a,b,c,a,b,a,b,c,a,b]

int main() {

    string s;     
    cin >> s;

    vector<long long> hsh = get_hash(s);
    vector<long long> p_pow(s.size() + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= (int)s.size(); i++)
        p_pow[i] = (p_pow[i - 1] * 31) % mod;
    int j = s.size();                                            
    for(int i = 0; i < (int)s.size()-1; i++){  // [1,2,3,4,5,6,7,8,9,10]
       
        long long suffix = (hsh[j] - (hsh[j-i-1] * p_pow[i+1]) % mod + mod) % mod;
       // cout << suffix << "->" << hsh[i+1]<<endl;
        if(hsh[i+1] == suffix) cout << i+1 << " ";

    }
   
    
    
}