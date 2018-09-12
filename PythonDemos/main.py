# -*- coding: utf-8 -*-


import numpy as np;
a = np.array([2, 0, 1, 5])
print(a)
print(a[:3])
print(a.min())
a.sort()
b = np.array([[1, 2, 3], [4, 5, 6]])
print(b * b)


#import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 10, 100)
y = np.sin(x) + 1
z = np.cos(x ** 2) + 1

plt.figure(figsize=(8, 4))
plt.plot(x, y, label='$\sin x+1$', color='red', linewidth=2)
plt.plot(x, z, 'b--', label='$\cos x^2+1$')
plt.rcParams['font.sans-serif'] = ['DFKai-SB']
plt.xlabel('Time (s) ')
plt.ylabel('Volt')
plt.title(u"A Simple Example 一个简单的例子")
plt.ylim(0, 2.2)
plt.legend()
plt.show()



import pandas as pd

s=pd.Series([1,2,3], index=['a','b','c'])
d=pd.DataFrame([[1,2,3],[4,5,6]],columns=['a','b','c'])
d2=pd.DataFrame(s)

print(d.head())
print(d.describe())

#pd.read_excel('C:\\users\\Administrator\\Desktop\\getMark.xls')
#pd.read_csv('C:\\users\\Administrator\\Desktop\\draft.txt', encoding='utf-8')

