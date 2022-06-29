# This script extracts the words from /usr/share/dict/words
# groups the words starting with the same letter and puts them to a file
# Ex: all letters starting with "a" are copied to "a.txt" and "b" to "b.txt"
# This also finds the file with maximum words and prints the first 20 words of the file

#!/bin/bash

max_words_cnt=0
max_words_letter=a
max_words_file=a.txt

for var in {a..z} ; do
    cat /usr/share/dict/words | grep ^$var > $var.txt
    current_word_cnt=$(cat $var.txt | wc -w)
    if [ $current_word_cnt -gt $max_words_cnt ] ; then
        max_words_cnt=$current_word_cnt
        max_words_letter=$var
        max_words_file=$var.txt
    fi
done

echo "The letter $max_words_letter begins with the largest number of words: $max_words_cnt"
head -n 20 $max_words_file

