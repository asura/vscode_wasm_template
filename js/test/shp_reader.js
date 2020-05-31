function readShp(filePath) {
	return new Promise((resolve, reject) => {
		fetch(filePath).then(function (response) {
			return response.arrayBuffer();
		}).then(function (arrayBuffer) {
			if (arrayBuffer) {
				// ファイル内容をWASM側のメモリへ転送

				var byteArray = new Uint8Array(arrayBuffer);

				var ptr = Module._malloc(arrayBuffer.byteLength);
				var result = new Uint8Array(Module.HEAPU8.buffer, ptr, arrayBuffer.byteLength);

				for (var i = 0; i < byteArray.byteLength; i++) {
					result[i] = byteArray[i];
				}

				resolve(Module.ccall(
					'getShapefileNRecord',
					'number',
					['ArrayBuffer', 'number'],
					[ptr, byteArray.byteLength]));

				Module._free(ptr);
			}
		});
	});
}

describe('readShp 関数のテスト', function () {
	describe('JavaScript側でファイルを読み込んでからwasm関数を呼び出し', function () {
		it('Shapefileの内容を与えるとレコード数を返す', function (done) {
			readShp('./ne_110m_land.shp').then(result => {
				expect(result).toBe(127);

				done();
			});
		});
	});
});
