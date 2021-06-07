class Solution {
public:
    vector<string> printVertically(string s) {
        //  istringstream has explicit constructor
        vector<string> wordStream{istream_iterator<string>{istringstream() = istringstream(s)}, istream_iterator<string>{}};

        // vector<string> wordStream{istream_iterator<string>{istringstream() = istringstream(s)}, {}};

        // vector<string> wordStream(istream_iterator<string>{istringstream() = istringstream(s)}, {});

        long long mxSz = (*max_element(begin(wordStream), end(wordStream), 
                            [](const string& s1, const string& s2) {return s1.size() < s2.size();})).size();

        vector<string> res(mxSz);

        //  for every word we are traversing the letter and andding it to the current string, if the size of the word is less, then we add a ' '
        for (long long i = 0; i < mxSz; ++i) {
          for (long long j = 0; j < wordStream.size(); ++j) {
            if (i < wordStream[j].size()) {
              res[i] += wordStream[j][i];
            } else {
              res[i] += " ";
            }
          }

          //    removng all the white spaces from the current word
          while (res[i].back() == ' ') res[i].pop_back();
        }

        return res;
    }
};
