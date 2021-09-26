class DFA:
    def __init__(self):
        self._substring = ""
        self._counting_substring = 0
        self._is_contained = False
        self._is_odd = False
        self._substring_len = 0

    def __clear_cache(self):
        self._counting_substring = 0
        self._is_contained = False
        self._is_odd = False
        self._substring_len = 0

    def checking_DFA(self, substring):
        self.__clear_cache()
        self._substring_len = len(self._substring)
        compare_string_count = 0
        for index, _ in enumerate(substring):
            if self._substring[compare_string_count] == substring[index]:
                compare_string_count += 1
            else:
                compare_string_count = 0
            if compare_string_count%self._substring_len == 0 and compare_string_count!=0:#if contained substring return contained signal
                self._is_contained = True
                self._counting_substring+=1
                compare_string_count=0
        self.__check_odd(self._counting_substring)#check if input string contained odd substring
        print(f"The [{substring}] in [{self._substring}]:")
        print(f"[Contained]   " + str(myDFA._is_contained))
        print(f"[Odd]         " + str(myDFA._is_odd))
        print(f"[Quantity]    "+str(myDFA._counting_substring))

    def __check_odd(self, counting):
        if counting==0:
            self._is_odd = True
            return
        if counting%2==0:
            #if counting equal 2,4,6... means it is not odd number
            self._is_odd = False
        else:
            #if counting equal 1,3,5... means it is odd number
            self._is_odd = True

    def _append_substring_word(self, this_string):
        self._substring = this_string
if __name__ == '__main__':
    myDFA = DFA()
    myDFA._append_substring_word("aa")
    myDFA.checking_DFA("bbb")
    myDFA.checking_DFA("aba")
    myDFA.checking_DFA("baaaa")
    myDFA.checking_DFA("a")
    myDFA.checking_DFA("ababab")
    myDFA.checking_DFA("abaaba")
