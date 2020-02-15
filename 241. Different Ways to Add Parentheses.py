class Solution(object):
    def __init__(self):
        super(Solution, self).__init__()
        self._saved_result = {}

    def diffWaysToCompute(self, input):
        parts = []
        number = 0
        # print("input: {}".format(input))
        for c in input:
            if c == '+' or c == '-' or c == '*':
                parts.append(number)
                number = 0
                parts.append(c)
            else:
                number = number * 10 + int(c)
        parts.append(number)
        # print("nodes: {}".format(parts))

        return self.get_results(parts, 0, len(parts))

    def get_results(self, parts, idx_l, idx_r, level=0):
        pre = ''
        for _ in range(level):
            pre += '    '
        # print("{} getResults: {}, {}, {}".format(pre, idx_l, idx_r, parts[idx_l:idx_r]))
        results = []
        cache_idx = "{}_{}".format(idx_l, idx_r)

        if cache_idx in self._saved_result:
            results = self._saved_result[cache_idx]
        else:
            if idx_r - idx_l == 1:
                # print("{} results from saved_results".format(pre))
                results.append(parts[idx_l])
            else:
                for i in range(idx_l, idx_r):
                    if parts[i] == '+' or parts[i] == '-' or parts[i] == '*':
                        # print("{} operator: idx={}, value={}, l={}, r={} ".format(pre, i, parts[i], idx_l, idx_r))
                        left_result = self.get_results(parts, idx_l, i,
                                                       level + 1)
                        right_result = self.get_results(parts, i + 1, idx_r,
                                                        level + 1)

                        for r_l in left_result:
                            for r_r in right_result:
                                if parts[i] == '+':
                                    results.append(r_l + r_r)
                                elif parts[i] == '-':
                                    results.append(r_l - r_r)
                                elif parts[i] == '*':
                                    results.append(r_l * r_r)
            self._saved_result[cache_idx] = results
        # print("{} results: {}".format(pre, results))
        # print("{} saved_result: {}".format(pre, self._saved_result))

        return results
