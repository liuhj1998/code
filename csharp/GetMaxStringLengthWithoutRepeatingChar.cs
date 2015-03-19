namespace maxLenWithoutRepeating
{
    public class Class1
    {
        public static int GetMaxLengthWithoutRepeatingChar(string s)
        {
            // first, check input param
            if ((s.Length == 0) || (s.Length == 1))
                return s.Length;

            int start = 0;
            int end = 1;
            int maxLen = 0;

            // assume ASCII chars, using an array to remember if the char has appeared or not
            bool[] charIndex = new bool[256];
            int len = charIndex.Length;
            for (int i = 0; i < len; ++i)
                charIndex[i] = false;

            // end starts at 1, so the first char has appeared
            charIndex[s[0]] = true;
            while (end < s.Length)
            {
                if (charIndex[s[end]] == false)
                {
                    // the char has not appeared, put it in
                    charIndex[s[end]] = true;
                    end += 1;
                }
                else
                {
                    maxLen = Math.Max(maxLen, end - start);
                    // the char has appeared, figure out where the new start should be                    
                    while (s[start] != s[end])
                    {
                        // clear the char out of the memory
                        charIndex[s[start]] = false;
                        start += 1;
                    }

                    // we need to move both index one more for next round
                    start += 1;
                    end += 1;
                }
            }

            maxLen = Math.Max(maxLen, end - start);

            return maxLen;
        }
    }
}

