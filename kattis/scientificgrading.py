from decimal import *
import math

def standardize(z):
    if z[0] == Decimal(0): return z
    log_sign = math.floor(abs(z[0]).log10())
    if log_sign > 0: return (z[0] * Decimal(10**(-log_sign)), z[1] + log_sign)
    elif log_sign < 0: return (z[0] * Decimal(10**(-log_sign)), z[1] + log_sign)
    else: return z

def true_val(x, y, op):
    if op == "*":
        return standardize((x[0] * y[0], x[1] + y[1]))
    if op == "/":
        return standardize((x[0] / y[0], x[1] - y[1]))
    if op == "-": 
        y = (y[0] * -1, y[1])
    if abs(x[1] - y[1]) < 15:
        if x[1] < y[1]: x, y = y, x
        return standardize((x[0] * (10 ** (x[1] - y[1])) + y[0], y[1]))
    else:
        if min(x[1], y[1]) > -9: return standardize((Decimal(1), 3e9))
        if x[1] > y[1]: return standardize(x)
        else: return standardize(y)

def rel_err(z, z_true):
    if z_true[0] == Decimal(0):
        if z == Decimal(0): return (Decimal(0), 0)
        else: return standardize((Decimal(1), 3e9))
    temp1 = true_val(z, z_true, "-")
    print(z)
    temp2 = true_val(temp1, z_true, "/")
    return standardize((abs(temp2[0]), temp2[1]))

def abs_err(z, z_true):
    temp1 = true_val(z, z_true, "-")
    return standardize((abs(temp1[0]), temp1[1]))

getcontext().prec = 200           
inputs, input_parts = [], []
for i in range(6):
    inputs.append(input())

for input in inputs:
    temp = input.split("e")
    sign1, sign2 = 1, 1
    if temp[0][0] == "-": sign1 = -1
    if temp[1][0] == "-": sign2 = -1
    input_parts.append((sign1 * Decimal(temp[0][1:]), sign2 * int(temp[1][1:])))

ops = ["+", "-", "*", "/"]

for index, op in enumerate(ops):
    z_true = true_val(input_parts[0], input_parts[1], op)
    # print(rel_err(input_parts[index + 2], z_true))
    big_rel_err = true_val(rel_err(input_parts[index + 2], z_true), (Decimal(1), -9), "-")[0] >= Decimal(0)
    big_abs_err = true_val(abs_err(input_parts[index + 2], z_true), (Decimal(1), -9), "-")[0] >= Decimal(0)
    if big_rel_err or big_abs_err:
        print("Incorrect")
    else:
        print("Correct")

"""
-2.000000000e+18346349
+2.000000000e+18346349
+1.000000000e-1235
+1.000000000e-1235
+1.000000000e+1235
-1.000000000e+0
"""