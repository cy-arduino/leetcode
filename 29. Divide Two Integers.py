class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = 1
        
        if dividend < 0:
            sign = 0-sign
            dividend = 0-dividend
        if divisor < 0:
            sign = 0-sign
            divisor = 0-divisor

        ret = 0
        while dividend >= divisor:
            quotient_add = 1
            tmp = divisor
            while tmp<<1 <= dividend:
                tmp <<= 1
                quotient_add += quotient_add
            dividend -= tmp
            ret += quotient_add
        
        if sign<0:
            ret=0-ret
            
        if ret > 2147483647:
            ret = 2147483647

        return ret
        
