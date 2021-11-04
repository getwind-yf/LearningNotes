
基础概念和类型：
-UPrimitiveComponent ： 图元组件，是所有可渲染物体的父类，是CPU层裁剪的最小粒度单位 
-FPrimitiveSceneProxy ： 图元场景代理，是UPrimitiveComponent的代表， 镜像了UPrimitiveComponent在渲染线程的状态
-FPrimitiveSceneInfo ： 渲染器内部状态，融合了UPrimitiveComponent & FPrimitiveSceneProxy，只存在于渲染器模块 
-FScene ：UWorld在渲染模块的代表，渲染线程拥有FScene的所有状态 
-FScene ：描述了FScene的单个视图View， 一个场景可被多个view绘制  
-FViewInfo ：view在渲染器的代表，只存在渲染器模块，引擎模块不可见 
