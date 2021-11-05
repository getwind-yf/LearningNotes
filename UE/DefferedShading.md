
Render Path 分类 ： 
- Forward Rendering 前向渲染 
- Defferred Rendering 延迟渲染 

FDefferredShadingSceneRenderer 包括以下步骤 
- InitViews 
- PrePass 
- BasePass 
- LightingPass 
- TranslucentPass 
- Postprocess  

Basic Concept : 
- Render Target (RT) 渲染目标或者纹理：指的是位于GPU显存的纹理缓冲区，用作颜色写入和混合的目标 
- Geometry Buffer (GBuffer) 几何缓冲区：延迟渲染中几何数据容器 
- Rendering Path 渲染路径：将场景渲染到渲染目标的步骤 
- Forward Shading：普通存在的渲染路径 

Deffered
