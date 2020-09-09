import pandas as pd

from fbprophet import Prophet
df= pd.DataFrame({'id': ['1','1','2','3'],'title': ['Striped Rug','Striped Rug2','Striped Rug3','Striped Rug4'],'description':['Black and white...','Black and white...','123Black and white...','Black and white...123'],'availability':['in stock','in stock','in stock','in stock'],'condition':['new','new','new','new',],'price':[22000 ,29000,27000,35000],'image_link':['https://drive.google.com/file/d/1voiPnNIwa9bB7aeCUKFIj4eAOYxGpSgK/view?usp=sharing','https://drive.google.com/file/d/1voiPnNIwa9bB7aeCUKFIj4eAOYxGpSgK/view?usp=sharing','https://drive.google.com/file/d/1cWtFrEQYVpAj4rA5_tbRBGToC9zlyTiX/view?usp=sharing','https://drive.google.com/file/d/1cWtFrEQYVpAj4rA5_tbRBGToC9zlyTiX/view?usp=sharing']})

# df = pd.DataFrame(cars, columns= ['id', 'title','description','availability','condition','price','link'],index=False)
compression_opts = dict(method='zip',
                        archive_name='out.csv')  
df.to_csv('out.zip', index=False,
          compression=compression_opts)  