long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

vector<int> kmp(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int countUniqueSubstrings(const string &inputString) {
    int stringLength = inputString.size();

    const int primeBase = 31;
    const int modulo = 1e9 + 9;
    vector<long long> primePowers(stringLength);
    primePowers[0] = 1;

    for (int i = 1; i < stringLength; i++)
        primePowers[i] = (primePowers[i - 1] * primeBase) % modulo;

    vector<long long> prefixHashes(stringLength + 1, 0);
    for (int i = 0; i < stringLength; i++)
        prefixHashes[i + 1] = (prefixHashes[i] + (inputString[i] - 'a' + 1) * primePowers[i]) % modulo;

    int countUnique = 0;
    for (int length = 1; length <= stringLength; length++) {
        unordered_set<long long> uniqueSubstrings;
        for (int i = 0; i <= stringLength - length; i++) {
            long long currentHash = (prefixHashes[i + length] + modulo - prefixHashes[i]) % modulo;
            currentHash = (currentHash * primePowers[stringLength - i - 1]) % modulo;
            uniqueSubstrings.insert(currentHash);
        }
        countUnique += uniqueSubstrings.size();
    }
    return countUnique;
}

// conversions

// char-'a' gives index in alphabet
// 'z'-'a' = 26
