/**
 * The Daily's Byte 05/23/2021
 *
 * Given 2 binary strings (strings containing only 1s and 0s),
 * return their sum (also as a binary string). Neither binary string will
 * contain leading 0s unless the string itself is 0.
 */

#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>

std::string add_binary(const std::string& lop, const std::string& rop)
{
    std::string result("");

    size_t left_len = lop.size();
    size_t right_len = rop.size();

    size_t min_len = right_len < left_len ? right_len : left_len;

    int carry = 0x0;

    for (size_t i = 0; i < min_len; i++) {
        char left = lop[left_len - i - 1] - '0';
        char right = rop[right_len - i - 1] - '0';
        char next_bit = left ^ right;
        
        if (carry) {
            next_bit ^= carry;            
            carry = ((left & right) | (right & carry)) | (left & carry);
        } else {
            carry = left & right;
        }

        result.append(std::to_string(next_bit));
    }

    if (left_len < right_len) {
        for (int i = right_len - left_len - 1; i >= 0; i--) {
            char next_bit = (rop[i] - '0')  ^ carry;
            carry = (rop[i] - '0') & carry;
            result.append(std::to_string(next_bit));
        }
    } else if (right_len < left_len) {
        for (int i = left_len - right_len - 1; i >= 0; i--) {
            char next_bit = (lop[i] - '0')  ^ carry;
            carry = (lop[i] - '0') & carry;
            result.append(std::to_string(next_bit));
        }
    }

    if (carry) result.append(std::to_string(carry));

    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::string tc1_left                     ("100");
    std::string tc1_right                      ("1");
    assert(add_binary(tc1_left, tc1_right) == "101");

    std::string tc2_left                      ("11");
    std::string tc2_right                      ("1");
    assert(add_binary(tc2_left, tc2_right) == "100");

    std::string tc3_left                        ("1");
    std::string tc3_right                       ("0");
    assert(add_binary(tc3_left, tc3_right) ==    "1");

    std::string tc4_left                        ("1001101010");
    std::string tc4_right                       ("1111111111");
    assert(add_binary(tc4_left, tc4_right) ==   "11001101001" );
    return 0;
}
