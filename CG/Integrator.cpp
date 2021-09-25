

template <typename Float, typename Spectrum>
class PathIntegrator: public MonteCarloIntegrator <Float, Spectrum> 
{
public:
  MTS_IMPORT_BASE(MonteCarloIntegrator, m_max_depth, m_rr_depth) 
  MTS_IMPORT_TYPES(Scene, Sampler, Medium, Emitter, EmitterPtr, BSDF, BSDFPtr) 
  
  PathIntegrator(const Properties &props):Base(props) { } 
  
  std::pair<Spectrum, Mask> sample( const Scene *scene, Sampler *sampler, const RayDifferential3f &ray_, const Medium*, Float*, Mask active) const override
  {
    MTS_MASKED_FUNCTION(ProfilerPhase::SamplingIntegratorSample, active); 
    
    RayDifferential3f ray=ray_; 
    
    Float eta(1.f); 
    
    Float emission_weight(1.f); 
    Spectrum throughput(1.f), result(0.f); 
    
    // First Intersection 
    
    SurfaceInteraction3f si=
