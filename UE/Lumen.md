
Lumen 的技术特征：
- 表面缓存 Surface Cache
- 屏幕追踪 Screen Tracing
- 光线追踪模式：包括软件光追和硬件光追 
  - 软件光追：依赖有向距离场SDF，合并网格的距离场到一个全局距离场Global Distance Field来加速光线的追踪；其中，细节追踪Detail Tracing是利用单独的网格距离场来达到高质量的GI，全局追踪则会损失一定的画质效果 
  - 硬件光追：

Lumen的基础类型 
- FLumenCard 是FLumenMeshCards的基本组成元素 
