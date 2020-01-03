# [Google Machine Learning Courses](https://developers.google.com/machine-learning/crash-course/ml-intro)  
## Introduction to ML
* First, it gives you a tool to reduce the time you spend programming.
* Second, it will you to customize your products(100 languages tranlate).
* Third, solve problems that you,as a programmer,have no idea to solve(recognize faces,understand speech).
* Fourth, change the way you think about a problem .
  * logic -> statistics analyze 
  * mathematical science -> natural science
## Framing  
* __BASIC PRAMEOWRK:__ supervised machine learning.
* __label(y):__ it's the target we're trying to predict,something like 'spam or not spam'.
* __feature(x<sub>i</sub>):__ any piece of information,something like words in the email.  
* __example(x):__ one piece of data,for example,one email.
* __labeled example(x,y)__  
* __unlabeled example(x,?)__
* __model(prediction(x)=y'):__ the thing that doing predicting,it's the thing that we're going to create.
## Descending into ML  
![Mean Square Error!](./src/mse.png)
## Reducing Loss
### Gradient Descent
![Loss Chart!](./src/losschart.png)
### Learning Rate
best learn rate!
## First Steps with TF  
![TensorFlow toolkit hierarchy!](./src/tf-hierarchy.png)
### TF Progarmming Exercise
* pandas  
    是一种数据分析API  
    ```python
    from __future__ import print_function
    import pandas as pd
    import numpy as np
    pd.__version__

    california_housing_dataframe = pd.read_csv("https://download.mlcc.google.cn/mledu-datasets/california_housing_train.csv", sep=",")
    california_housing_dataframe.describe()
    california_housing_dataframe.head()
    california_housing_dataframe.hist('housing_median_age')

    city_names = pd.Series(['San Francisco', 'San Jose', 'Sacramento'])
    population = pd.Series([852469, 1015785, 485199])
    citys = pd.DataFrame({ 'City name': city_names, 'Population': population})
    print(type(cities['City name']))
    cities['City name']
    population / 1000.
    np.log(population)
    population.apply(lambda val: val > 1000000)
    ```
* first steps with tensorflow  
```python
from __future__ import print_function
import math
from IPython import display
from matplotlib import cm
from matplotlib import gridspec
from matplotlib import pyplot as plt
import numpy as np
import pandas as pd
from sklearn import metrics
%tensorflow_version 1.x
import tensorflow as tf
from tensorflow.python.data import Dataset

tf.logging.set_verbosity(tf.logging.ERROR)
pd.options.display.max_rows = 10
pd.options.display.float_format = '{:.1f}'.format

california_housing_dataframe = pd.read_csv("https://download.mlcc.google.cn/mledu-datasets/california_housing_train.csv", sep=",")

california_housing_dataframe = california_housing_dataframe.reindex(np.random.permutation(california_housing_dataframe.index))
california_housing_dataframe["median_house_value"] /= 1000.0
california_housing_dataframe
california_housing_dataframe.describe()
```
