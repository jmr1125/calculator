# calculator
生成计算题与答案

需求 qpdf-11.4.0 (可选)

xiaozan.conf
[0-9][lr] 表示范围 并随机生成
--------
```def``` 定义 由equ 表示 不由随机数生成
```equ``` 数字表示变量 由后缀表达示组成并自动计算
--------
```type:*``` 定义类型
```endtype``` 结束定义
--------
```for``` 格式 $[数字]  表示定义格式 $[0-9]替换为变量
--------
example [xiaozan.conf](https://github.com/jmr1125/calculator/blob/main/xiaozan.conf)
