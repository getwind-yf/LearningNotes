
材质体系 

- UMaterial 

- FMaterialRenderProxy 
  - UMaterialInterface对应的渲染线程代理是FMaterialRenderProxy，负责接收游戏线程代表的数据，然后传递给渲染器去处理和渲染 
  - 定义了静态全局的材质渲染代理映射表和获取FMaterial渲染实例的接口 
