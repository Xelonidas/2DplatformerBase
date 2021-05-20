#ifndef ANIMATORS_HPP
#define ANIMATORS_HPP

namespace obj {
	void initStatics();
	
	extern GLuint textureAtlas;
	
	class block;

	typedef struct {
		uint8_t UVsx;
		uint8_t UVsy;
	} UVoffset;

	class animator {		
	public:
		
		virtual void stateFunction(block* b) = 0;
		virtual UVoffset getTexture(block* b) = 0;
	};
	
	class staticAnimator : public animator {
	public:
		UVoffset uv; 
		staticAnimator(UVoffset off);
		~staticAnimator();
		
		void stateFunction(block *b) override;
		UVoffset getTexture(block* b)  override;
	};
	
	class synchronusLoopedAnimator : public animator {
	public:
		UVoffset* uv; 
		int l;
		synchronusLoopedAnimator(UVoffset* t, int len);
		~synchronusLoopedAnimator();
		
		void stateFunction(block *b) override;
		UVoffset getTexture(block *b) override;
	};
	
	class multiStableAnimator : public animator {
	public:
		UVoffset* uv; 
		int l;
		multiStableAnimator(UVoffset* t, int len);
		~multiStableAnimator();
		
		void stateFunction(block *b) override;
		UVoffset getTexture(block *b) override;
	};
}

#endif
