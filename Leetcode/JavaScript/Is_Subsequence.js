function isSubsequence(s, t) 
{
   let i = 0, j = 0;
        while ((i < s.length) && (j < t.length))
        {
            if (s[i] == t[j]) i += 1;
            j += 1;
        }     
        return i == s.length;
}

console.log(isSubsequence("axc", "ahbgdc"));
