// CSNode.h - a node that builds a C# assembly
//------------------------------------------------------------------------------
#pragma once
#ifndef FBUILD_GRAPH_CSNODE_H
#define FBUILD_GRAPH_CSNODE_H

// Includes
//------------------------------------------------------------------------------
#include "FileNode.h"
#include "Core/Containers/Array.h"

// Forward Declarations
//------------------------------------------------------------------------------
class Args;

// CSNode
//------------------------------------------------------------------------------
class CSNode : public FileNode
{
public:
	explicit CSNode( const AString & compilerOutput,
					 const Dependencies & inputNodes,
					 const AString & compiler,
					 const AString & compilerArgs,
					 const Dependencies & extraRefs );
	virtual ~CSNode();

	static inline Node::Type GetTypeS() { return Node::CS_NODE; }

	virtual void Save( IOStream & stream ) const;
	static Node * Load( IOStream & stream );
private:
	virtual bool DoDynamicDependencies( bool forceClean );
	virtual BuildResult DoBuild( Job * job );

	void EmitCompilationMessage( const Args & fullArgs ) const;

	bool BuildArgs( Args & fullArgs ) const;
	void GetInputFiles( Args & fullArgs, const AString & pre, const AString & post ) const;
	void GetExtraRefs( Args & fullArgs, const AString & pre, const AString & post ) const;

	AString m_CompilerPath;
	AString m_CompilerArgs;

	Dependencies m_ExtraRefs;
};

//------------------------------------------------------------------------------
#endif // FBUILD_GRAPH_CSNODE_H
