#ifndef CONFIGURACION_H
#define CONFIGURACION_H

class Configuracion{

	public:
		int diametroBolas;
		bool ratonActuaJugador;
		int intervaloAnimacion;	
		int anchuraPantalla;
		int alturaPantalla;
		bool bolaJugadorSolida;
		bool activarControlRaton;
		int configuracionGravedad;
		
		static const int INTERVALO_LENTO = 50;
		static const int INTERVALO_MEDIO = 20;
		static const int INTERVALO_RAPIDO = 10;

		bool configuracionActualizada;

		int vidas;
};

#endif
