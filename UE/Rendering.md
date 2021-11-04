
基础概念和类型：
-UPrimitiveComponent ： 图元组件，是所有可渲染物体的父类，是CPU层裁剪的最小粒度单位 
-FPrimitiveSceneProxy ： 图元场景代理，是UPrimitiveComponent的代表， 镜像了UPrimitiveComponent在渲染线程的状态
-FPrimitiveSceneInfo ： 渲染器内部状态，融合了UPrimitiveComponent & FPrimitiveSceneProxy，只存在于渲染器模块 
-FScene ：UWorld在渲染模块的代表，渲染线程拥有FScene的所有状态 
-FScene ：描述了FScene的单个视图View， 一个场景可被多个view绘制  
-FViewInfo ：view在渲染器的代表，只存在渲染器模块，引擎模块不可见 
-FSceneRenderer ： 每帧都会被创建，封装帧间临时数据； 派生出 FDeferredShadingSceneRenderer & FMobileSceneRenderer 
-FMeshBatchElement：单个网格模型的数据，包含顶点、索引、UniformBuffer及标识 
-FMeshBatch：存在一组MeshBatchElement数据，这组数据拥有相同的材质和顶点缓冲 
-FMeshDrawCommand：完整描述一个Pass Draw Call的所有状态和数据， shader绑定、顶点数据、索引数据、PSO缓存等 
-FMeshPassProcessor：网格渲染Pass处理器，负责将场景中感兴趣的网格对象执行处理，由FMeshBatch转成多个FMeshDrawCommand 

除了UPrimitiveComponent是属于游戏线程对象，其他都属于渲染线程 

渲染流程：
在调用图形API之前，需要遮挡剔除、动态和静态合批、动态Instance、缓存状态和命令、生成中间指令再转译成图形API 

旧版本的Mesh Draw Pipleline：
FPrimitiveSceneProxy -> FMeshBatch -> 调用方法RenderBasePase() -> Set of RHICommandList commands -> DrawindexedPrimitive 
经过可见性测试的PrimitiveSceneProxy利用其接口收集不同 



-FMeshPassProcessor主要作用是：
  - Pass过滤
  - 选择绘制命令所需的Shader及渲染状态
  - 收集绘制命令及Shader的资源绑定 
  - 收集Draw Call相关的参数

从RHICommandList到GPU
- RHI全程是Rendering Hardware Interface（渲染硬件接口），是不同图形API的抽象层，负责收录与图形API无关的中间层绘制指令和数据 


总结：
优化的内容 
- 绘制调用合并 FMeshDrawCommands 
- 动态实例化 
- 并行绘制 
- 缓存绘制指令 
- 提升缓存命中率





