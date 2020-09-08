import pandas as pd
import numpy as np
raw_data = {'first_name': ['Jason', 'Molly', 'Tina', 'Jake', 'Amy'], 
        'last_name': ['Miller', 'Jacobson', ".", 'Milner', 'Cooze'], 
        'age': [42, 52, 36, 24, 73], 
        'preTestScore': [4, 24, 31, ".", "."],
        'postTestScore': ["25,000", "94,000", 57, 62, 70]}
df = pd.DataFrame(raw_data, columns = ['first_name', 'last_name', 'age', 'preTestScore', 'postTestScore'])

df.to_csv('example.csv')
df1=pd.read_csv('HOGFull1Font-imagesize-50-block-20-cell-20-bin-9-sined-True-nimage-30000.csv',sep = '\t',usecols= range(1,145))
df1.to_csv('example3.csv')
print(df1)

