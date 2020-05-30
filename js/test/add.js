describe('add 関数のテスト', function () {
	it('1と2を与えると3を返す', function () {
		expect(Module._add(1, 2)).toBe(3);
	});
	it('2と-3を与えると-1を返す', function () {
		expect(Module._add(2, -3)).toBe(-1);
	});
});
