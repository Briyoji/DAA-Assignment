import pandas as pd
import numpy as np

df = pd.read_csv('out.csv', names=['N', 'LeftMost', 'Median'])
print(df)

df['N'] = df['N'].astype(int)
df['LeftMost'] = df['LeftMost'].astype(float) * 1000
df['Median'] = df['Median'].astype(float) * 1000

import matplotlib.pyplot as plt

plt.plot(np.array(df['N']), np.array(df['LeftMost']), label='LeftMost')
plt.plot(np.array(df['N']), np.array(df['Median']), label='Median')

plt.xlabel('N')
plt.ylabel('Time (ms)')
plt.title('LeftMost and Median')
plt.legend()
plt.show()