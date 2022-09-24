# 代码文件说明
BinarySearch.cpp是在有序数组中查找某数。    
TwoSearch.cpp分别是在有序数组中找>=k的最左侧位置和<=k的最右侧位置。  
有时候答案也可以二分，不一定是要在数组中找位置，给你一区间，答案就在这个区间按，可以用二分的思想去试。
关于二分的两个模板的使用如下：  
![kk](https://user-images.githubusercontent.com/40891397/192098369-a33551a9-effd-42e7-aef8-35f3ba8afb4c.png)  
假设有一个总区间，经由我们的check函数判断后，可分成两部分，以o作true，以.....作false示意较好识别如果我们的目标是下面这个v，那麽就必须使用模板1  
................vooooooooo  
假设经由check划分后，整个区间的属性与目标v如下，则我们必须使用模板2  
oooooooov...................  
其中check(v) = true，且这里的check()就相当于代码中的arr\[mid\]<=k或者arr\[mid\]>=k的判断。  
