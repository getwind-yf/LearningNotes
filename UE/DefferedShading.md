
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

Deffered Rendering: 
- 第一个Pass是几何通道，将场景中的物体光栅化到多个GBuffer上 
- 第二个Pass是利用GBuffer的几何信息计算每个像素的光照结果 

Geometry Pass: 
- 将场景中不透明物Opaque和Masked物体 用无光照的材质渲染，写入RT中 （写入内容包括：位置、法线、材质参数Diffuse/Emissive/Specular/AO/Roughness） 
- 目的是：避免遮挡物体的光照计算，避免了Overdraw
''' 
void RenderBasePass() 
{
  SetupGBuffer(); 
  for each(Object in OpaqueAndMaskedObjectsInScene) 
  {
    SetUnlitMaterial(Object); 
    DrawObjectToGBuffer(Object); 
   }
}

Lighting Pass:
- 利用GBuffer执行光照计算，逻辑是遍历渲染分辨率相同的像素，根据UV来采样该像素的几何信息 
- 优劣：优点是跟物体数量







