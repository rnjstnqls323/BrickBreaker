#pragma once

class Shader
{
protected:
    Shader() = default;
    virtual ~Shader() = default;

public:
    static class VertexShader* AddVS(wstring file);
    static class PixelShader* AddPS(wstring file);

    static void Delete();

    virtual void Set() = 0;

protected:
    ID3DBlob* blob;

    static unordered_map<wstring, Shader*> shaders;
};