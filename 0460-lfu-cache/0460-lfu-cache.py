class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = dict() # key -> [value, count]
        self.cache_counts = dict() # count -> OrderedDict(key -> None)
        self.min_count = 0

    def get(self, key: int) -> int:
        if key not in self.cache: 
            return -1
        
        value, old_count = self.cache[key]
        self.cache[key][1] += 1
        self.cache_counts[old_count].pop(key)
        self.update_cache_counts(key, old_count + 1)

        # if the old count was the previous minimum and there exists no more cache items
        # for that minimum then increment
        if old_count == self.min_count and len(self.cache_counts[old_count]) == 0:
            self.min_count = old_count + 1

        return value

    def put(self, key: int, value: int) -> None:
        if self.capacity <= 0: return

        # key exists,
        if key in self.cache:
            _ = self.get(key) # reuse get method to update count 
            self.cache[key][0] = value # update value for the key
            return

        # need to make room in the cache
        if len(self.cache) == self.capacity:
            rm_key, _ = self.cache_counts[self.min_count].popitem(False)
            self.cache.pop(rm_key)
  
        # insert into cache
        self.cache[key] = [value, 1] 
        self.update_cache_counts(key, 1)
        self.min_count = 1

    def update_cache_counts(self, key: int, count: int):
        # first occurence of frequency
        if count not in self.cache_counts: 
            self.cache_counts[count] = collections.OrderedDict()

        # add to counts
        self.cache_counts[count][key] = None