# 空间分析与建模实验







## 柏林市房价分析

第一个实验是根据pysal官方的esda库中的教程去做的，本着熟悉一下利用python对空间数据进行处理和分析的流程，去跑了一个官方的示例，从中加深了利用geopandas库对空间数据处理的方法，并且巩固了空间自相关的课程知识，对柏林市房价进行全局莫兰指数和局部莫兰指数的探索，并检验。



首先绘制了柏林市平均房价图

![image-20240402212028657](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402212028657.png)

![image-20240402212116446](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402212116446.png)

统计出房价高于平均房价的地区数量与完全随机模式下的数量进行对比，判断柏林房价是否存在空间自相关，经计算通过检验。



分析局部莫兰指数，绘制了莫兰散点图

![image-20240402214355260](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402214355260.png)

做出LISA图

![image-20240402214451048](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402214451048.png)

## 纽约市枪击事件分析

经过了示例的学习，掌握了空间分析的基础，对pysal库有了一定的了解，选取了纽约市2018-2020枪击事件进行分析，首先对数据进行处理和清洗，进行空间自相关分析（全局，局部），由于空间异质性的存在，又进行了地理加权回归分析（GWR，MGWR）分析自变量对因变量的空间影响。

纽约市枪击事件空间分布

![image-20240402214855918](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402214855918.png)



### 空间相关性分析

全局莫兰指数计算，通过检验，纽约市枪击事件存在空间相关性

![image-20240402214923254](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402214923254.png)

![image-20240402214940590](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402214940590.png)

局部莫兰指数分析

莫兰散点图：

![image-20240402215039177](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402215039177.png)

LISA图：

![image-20240402215026739](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402215026739.png)



### 地理加权回归分析



GWR分析

![image-20240402215227079](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402215227079.png)

![image-20240402215344967](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402215344967.png)



MGWR分析

![image-20240402215358852](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402215358852.png)

![image-20240402215437088](http://sa33v5v2e.hd-bkt.clouddn.com/image-20240402215437088.png)