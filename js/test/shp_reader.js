function readShp(filePath) {
	return new Promise((resolve, reject) => {
		fetch(filePath).then(function (response) {
			return response.arrayBuffer();
		}).then(function (arrayBuffer) {
			if (arrayBuffer) {
				// ファイル内容をWASM側のメモリへ転送
				let byteArray = new Uint8Array(arrayBuffer);
				let ptr = Module._malloc(arrayBuffer.byteLength);
				Module.HEAPU8.set(byteArray, ptr);

				resolve(Module.ccall(
					'getShapefileNRecord',
					'number',
					['number', 'number'],
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
