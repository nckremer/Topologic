#pragma once

#include "Topology.h"

#include <list>

#include <TopoDS_CompSolid.hxx>

namespace TopologicCore
{
	class Cell;
	class Vertex;
	class Edge;
	class Wire;
	class Face;
	class Shell;

	class CellComplexGUID
	{
	public:
		static std::string Get()
		{
			return std::string("4ec9904b-dc01-42df-9647-2e58c2e08e78");
		}
	};

	/// <summary>
	/// 
	/// </summary>
	class CellComplex : public Topology
	{
	public:
		typedef std::shared_ptr<CellComplex> Ptr;

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkOcctCompSolid"></param>
		CellComplex(const TopoDS_CompSolid& rkOcctCompSolid, const std::string& rkGuid = "");

		virtual ~CellComplex();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rCells"></param>
		TOPOLOGIC_API void Cells(std::list<std::shared_ptr<Cell>>& rCells) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rCells"></param>
		TOPOLOGIC_API void Faces(std::list<std::shared_ptr<Face>>& rFaces) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rShells"></param>
		TOPOLOGIC_API void Shells(std::list<std::shared_ptr<Shell>>& rShells) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rEdges"></param>
		TOPOLOGIC_API void Edges(std::list<std::shared_ptr<Edge>>& rEdges) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rVertices"></param>
		TOPOLOGIC_API void Vertices(std::list<std::shared_ptr<Vertex>>& rVertices) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rWires"></param>
		TOPOLOGIC_API void Wires(std::list<std::shared_ptr<Wire>>& rWires) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkCells"></param>
		/// <returns></returns>
		static TOPOLOGIC_API std::shared_ptr<CellComplex> ByCells(const std::list<std::shared_ptr<Cell>>& rkCells);

		static TopoDS_CompSolid ByOcctSolids(const TopTools_ListOfShape& rkOcctSolids);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkFaces"></param>
		/// <returns></returns> 
		static TOPOLOGIC_API std::shared_ptr<CellComplex> ByFaces(const std::list<std::shared_ptr<Face>>& rkFaces, const double kTolerance);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		TOPOLOGIC_API std::shared_ptr<Cell> ExternalBoundary() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkInternalFaces"></param>
		/// <returns></returns>
		TOPOLOGIC_API void InternalBoundaries(std::list<std::shared_ptr<Face>>& rInternalFaces) const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual bool IsManifold() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rNonManifoldFaces"></param>
		/// <returns></returns>
		TOPOLOGIC_API void NonManifoldFaces(std::list<std::shared_ptr<Face>>& rNonManifoldFaces) const;

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
		virtual TopoDS_CompSolid& GetOcctCompSolid();

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual const TopoDS_CompSolid& GetOcctCompSolid() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkOcctShape"></param>
		virtual void SetOcctShape(const TopoDS_Shape& rkOcctShape);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkOcctCompSolid"></param>
		void SetOcctCompSolid(const TopoDS_CompSolid& rkOcctCompSolid);

		/// <summary>
		/// 
		/// </summary>
		virtual std::shared_ptr<Vertex> CenterOfMass() const;

		static TopoDS_Vertex CenterOfMass(const TopoDS_CompSolid& rkOcctCompSolid);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rOcctGeometries"></param>
		virtual void Geometry(std::list<Handle(Geom_Geometry)>& rOcctGeometries) const;

		virtual TopologyType GetType() const { return TOPOLOGY_CELLCOMPLEX; }

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual std::string GetTypeAsString() const;

		virtual std::string GetClassGUID() const {
			return CellComplexGUID::Get();
		}

		static TOPOLOGIC_API int Type() { return TopologicCore::TOPOLOGY_CELLCOMPLEX; }

		virtual bool IsContainerType() { return true; }

	protected:
		/// <summary>
		/// The underlying OCCT cell complex.
		/// </summary>
		TopoDS_CompSolid m_occtCompSolid;
	};
}