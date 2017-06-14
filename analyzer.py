import nltk
from nltk.tokenize import TweetTokenizer

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.positives_set = set()
        pos = open(positives, "r")
        for line in pos:
            if line.startswith(';') == False:
                self.positives_set.add(line.rstrip("\n"))
        pos.close()
        
        self.negatives_set = set()
        neg = open(negatives, "r")
        for line in neg:
            if line.startswith(';') == False:
                self.negatives_set.add(line.rstrip("\n"))
        neg.close()
        
        
        

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(tweet)
        sum = 0
        for word in tokens:
            if word.lower() in self.positives_set:
                sum += 1
            elif word.lower() in self.negatives_set:
                sum -= 1
            else:
                continue
        
        return sum
        """return 0 """
