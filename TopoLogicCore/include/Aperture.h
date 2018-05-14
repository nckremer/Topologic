#pragma once

#include "Utilities.h"
#include "Topology.h"
#include "AperturePath.h"

#include <list>
#include <memory>

namespace TopologicCore
{
	class Context;

	/// <summary>
	/// <para>
	/// An Aperture defines a connection path between two Topologies that share a common Topology or between a
	/// Topology and the outside space. A connection path can be uni-directional or bi-directional.
	/// </para>
	/// </summary>
	class Aperture : public Topology
	{
	public:
		Aperture(const std::shared_ptr<TopologicCore::Topology>& kpTopology, const std::shared_ptr<Context>& kpContext, const bool kOpenStatus);
		~Aperture();

		/// <summary>
		/// Creates an aperture by a topology and a context.
		/// </summary>
		/// <param name="kpTopology"></param>
		/// <param name="kpContext"></param>
		/// <returns></returns>
		static TOPOLOGIC_API std::shared_ptr<Aperture> ByTopologyContext(const std::shared_ptr<TopologicCore::Topology>& kpTopology, const std::shared_ptr<Context>& kpContext);

		/// <summary>
		/// Creates an aperture by a topology and a context.
		/// </summary>
		/// <param name="kpTopology"></param>
		/// <param name="kpContext"></param>
		/// <param name="kOpenStatus"></param>
		/// <returns></returns>
		static TOPOLOGIC_API std::shared_ptr<Aperture> ByTopologyContextStatus(const std::shared_ptr<TopologicCore::Topology>& kpTopology, const std::shared_ptr<Context>& kpContext, const bool kOpenStatus);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		TOPOLOGIC_API std::shared_ptr<Topology> Topology() const;

		/// <summary>
		/// Checks if any aperture path is open.
		/// </summary>
		/// <returns></returns>
		TOPOLOGIC_API bool IsOpen() const;

		/// <summary>
		/// Checks if the topologies are adjacent.
		/// </summary>
		/// <param name="rkTopologies"></param>
		/// <returns></returns>
		TOPOLOGIC_API bool IsOpen(const std::array<std::shared_ptr<TopologicCore::Topology>, 2>& rkTopologies) const;

		/// <summary>
		/// Returns all open aperture paths
		/// </summary>
		/// <param name="rPaths"></param>
		TOPOLOGIC_API void Paths(std::list<std::list<std::shared_ptr<TopologicCore::Topology>>>& rPaths) const;

		/// <summary>
		/// 
		/// </summary>
		TOPOLOGIC_API void Open();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkTopologies"></param>
		TOPOLOGIC_API void Open(const std::array<std::shared_ptr<TopologicCore::Topology>, 2>& rkTopologies);

		/// <summary>
		/// 
		/// </summary>
		TOPOLOGIC_API void Close();
		
		/// <summary>
		/// Checks if the topologies are adjacent.
		/// </summary>
		/// <param name="rkTopologies"></param>
		TOPOLOGIC_API void Close(const std::array<std::shared_ptr<TopologicCore::Topology>, 2>& rkTopologies);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rOcctGeometries"></param>
		virtual void Geometry(std::list<Handle(Geom_Geometry)>& rOcctGeometries) const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual TopoDS_Shape& GetOcctShape();

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual const TopoDS_Shape& GetOcctShape() const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual TopologyType GetType() const;

	protected:
		std::list<AperturePath> m_occtAperturePaths;
		std::shared_ptr<Context> m_pMainContext; // the primary context passed in the constructor is stored here
		std::shared_ptr<TopologicCore::Topology> m_pTopology;
	};
}